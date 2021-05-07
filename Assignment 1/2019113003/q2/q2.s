.text
.global find_transpose

find_transpose:
    # array in %rdi
    # transpose_array in %rsi
    # row in %rdx
    # col in %rcx
    # i in %r8
    # j in %r9

    movq $-1, %r8       # i = -1

.outerloop:
    inc %r8             # i++
    cmpq %r8, %rdx      # check row - i > 0  
    je .mainexit

    movq $0, %r9        # j = 0
    .innerloop:
        cmpq %r9, %rcx  # check col - j > 0 
        je .outerloop

        # main work happening
        # r10 = (j + i*col)
        movq %rcx, %r10             # temp = col
        imulq %r8, %r10             # temp = col*i
        addq %r9, %r10              # temp = i*col + j
        movq (%rdi, %r10, 8), %r11    # r11 = *(arr + (i*col + j)*8)

        # r12 = (i + j*row) 
        movq %rdx, %r12             # temp = row    
        imulq %r9, %r12             # temp = row*j
        addq %r8, %r12              # temp = row*j + i
        movq %r11, (%rsi, %r12, 8)    # *(transpose + (j*row + i)*8) = r11 

        inc %r9         # j++
        jmp .innerloop
    
.mainexit:
    ret
