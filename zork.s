.name "zork"
.comment "I'M ALIIIIVE"

l2:		live %2000
		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
