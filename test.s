.name "zork"
.comment "I'M ALIIIIIVE"

l2:
sti r1, %:live, %1
		and r1, %0, r1
		xor r1, r1, r1

live:	live%42
		zjmp %:live
