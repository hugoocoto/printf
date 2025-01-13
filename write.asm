section .data

section .text

write:
        mov rax, 1 ;; write
        syscall
        ret
