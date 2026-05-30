	.arch armv8.5-a
	.build_version macos,  26, 0
	.text
	.cstring
	.align	3
lC1:
	.ascii "=== \354\243\274\354\206\214 \353\271\204\352\265\220 (\353\252\250\353\221\220 \352\260\231\354\235\214) ===\0"
	.align	3
lC2:
	.ascii "&arr    = %p\12\0"
	.align	3
lC3:
	.ascii "arr     = %p\12\0"
	.align	3
lC4:
	.ascii "*arr    = %p\12\0"
	.align	3
lC5:
	.ascii "**arr   = %p\12\0"
	.align	3
lC6:
	.ascii "***arr  = %d\12\12\0"
	.align	3
lC7:
	.ascii "=== +1\354\235\230 \354\240\220\355\224\204 \353\213\250\354\234\204 \353\271\204\352\265\220 ===\0"
	.align	3
lC8:
	.ascii "sizeof(arr)      = %zu (\354\240\204\354\262\264)\12\0"
	.align	3
lC9:
	.ascii "sizeof(*arr)     = %zu (2D \355\217\211\353\251\264)\12\0"
	.align	3
lC10:
	.ascii "sizeof(**arr)    = %zu (1D \355\226\211)\12\0"
	.align	3
lC11:
	.ascii "sizeof(***arr)   = %zu (int \352\260\222)\12\0"
	.align	3
lC12:
	.ascii "\12=== +1 \352\262\260\352\263\274 ===\0"
	.align	3
lC13:
	.ascii "&arr + 1   = %p (\354\240\220\355\224\204: %ld)\12\0"
	.align	3
lC14:
	.ascii "arr + 1    = %p (\354\240\220\355\224\204: %ld)\12\0"
	.align	3
lC15:
	.ascii "*arr + 1   = %p (\354\240\220\355\224\204: %ld)\12\0"
	.align	3
lC16:
	.ascii "**arr + 1  = %p (\354\240\220\355\224\204: %ld)\12\0"
	.text
	.align	2
	.globl _main
_main:
LFB1:
	sub	sp, sp, #80
LCFI0:
	stp	x29, x30, [sp, 16]
LCFI1:
	add	x29, sp, 16
LCFI2:
	adrp	x0, lC0@PAGE
	add	x1, x0, lC0@PAGEOFF;
	add	x0, x29, 16
	ldr	q29, [x1]
	ldr	q30, [x1, 16]
	ldr	q31, [x1, 32]
	str	q29, [x0]
	str	q30, [x0, 16]
	str	q31, [x0, 32]
	adrp	x0, lC1@PAGE
	add	x0, x0, lC1@PAGEOFF;
	bl	_puts
	add	x0, x29, 16
	str	x0, [sp]
	adrp	x0, lC2@PAGE
	add	x0, x0, lC2@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	str	x0, [sp]
	adrp	x0, lC3@PAGE
	add	x0, x0, lC3@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	str	x0, [sp]
	adrp	x0, lC4@PAGE
	add	x0, x0, lC4@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	str	x0, [sp]
	adrp	x0, lC5@PAGE
	add	x0, x0, lC5@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	ldr	w0, [x0]
	str	w0, [sp]
	adrp	x0, lC6@PAGE
	add	x0, x0, lC6@PAGEOFF;
	bl	_printf
	adrp	x0, lC7@PAGE
	add	x0, x0, lC7@PAGEOFF;
	bl	_puts
	mov	x0, 48
	str	x0, [sp]
	adrp	x0, lC8@PAGE
	add	x0, x0, lC8@PAGEOFF;
	bl	_printf
	mov	x0, 24
	str	x0, [sp]
	adrp	x0, lC9@PAGE
	add	x0, x0, lC9@PAGEOFF;
	bl	_printf
	mov	x0, 12
	str	x0, [sp]
	adrp	x0, lC10@PAGE
	add	x0, x0, lC10@PAGEOFF;
	bl	_printf
	mov	x0, 4
	str	x0, [sp]
	adrp	x0, lC11@PAGE
	add	x0, x0, lC11@PAGEOFF;
	bl	_printf
	adrp	x0, lC12@PAGE
	add	x0, x0, lC12@PAGEOFF;
	bl	_puts
	add	x0, x29, 16
	add	x0, x0, 48
	mov	x1, 48
	str	x1, [sp, 8]
	str	x0, [sp]
	adrp	x0, lC13@PAGE
	add	x0, x0, lC13@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	add	x0, x0, 24
	mov	x1, 24
	str	x1, [sp, 8]
	str	x0, [sp]
	adrp	x0, lC14@PAGE
	add	x0, x0, lC14@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	add	x0, x0, 12
	mov	x1, 12
	str	x1, [sp, 8]
	str	x0, [sp]
	adrp	x0, lC15@PAGE
	add	x0, x0, lC15@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	add	x0, x0, 4
	mov	x1, 4
	str	x1, [sp, 8]
	str	x0, [sp]
	adrp	x0, lC16@PAGE
	add	x0, x0, lC16@PAGEOFF;
	bl	_printf
	mov	w0, 0
	ldp	x29, x30, [sp, 16]
	add	sp, sp, 80
LCFI3:
	ret
LFE1:
	.const
	.align	2
lC0:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.word	9
	.word	10
	.word	11
	.word	12
	.text
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x3
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB1-.
	.set L$set$2,LFE1-LFB1
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB1
	.long L$set$3
	.byte	0xe
	.uleb128 0x50
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0x9d
	.uleb128 0x8
	.byte	0x9e
	.uleb128 0x7
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.uleb128 0x1d
	.uleb128 0x40
	.byte	0x4
	.set L$set$6,LCFI3-LCFI2
	.long L$set$6
	.byte	0xdd
	.byte	0xde
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 15.2.0_1) 15.2.0"
	.subsections_via_symbols
