section .text
    bits 64
    default rel
    extern printf
    global dotproduct

dotproduct:

    xorps xmm0, xmm0                ; clear xmm0 (dot product holder)

dot_loop:
    cmp r8, 0                       ; check if n = 0
    jz dot_done                     ; if n = 0, jump to dot_done for returning the dot product

    movss xmm1, dword [rcx]         ; load a[i] (4 bytes float) into xmm1
    movss xmm2, dword [rdx]         ; load b[i] (4 bytes float) into xmm2
    mulss xmm1, xmm2                ; xmm1 = a[i] * b[i], where a[i] is xmm1 and b[i] is xmm2
    addss xmm0, xmm1                ; accumulate: xmm0 += xmm1

    add rcx, 4                      ; move to the next float in a (4 bytes per float)
    add rdx, 4                      ; move to the next float in b (4 bytes per float)
    dec r8                          ; decrement n (length of array)
    jmp dot_loop                    ; loop back

dot_done:
    ret                             ; return dot product in xmm0