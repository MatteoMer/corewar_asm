# Corewar ASM compiler
My part of one of the final project of the first part of the 42 cursus
It's a compiler of a pseudo-asm language.

The bytecode generated are used in a other part of the subject!

### How to create a champ (not a good one, just one that don't throw an error)
 - You should have a `.name` and `.comment` section with something in !
 - You should use choose an instruction and some args, that work with (be carefull with the type of the argument!)
 - The operation are described here : https://docs.google.com/spreadsheets/d/1pFwSCne-mh-u5ZLsjZS8VI9QvecYk-gWTyNaPstjpLE/edit#gid=0
 
### What is my program doing ?
 - I'm parsing the .s file that you're giving to me !
      * I'm getting the `.name` and `.comment` and keep it safe in my cool structure 😎
      * If there's a label ( `label:` for instance ), I'm adding it to a list of labels, keeping his address in this list
      * And I'm parsing all the instructions with his args, adding all instructions in another linked list!
 - After, I'm looking for calls to a label in my instruction ( ` jmp %:label ` for instance), and change the content of the instruction by the address of the label!
 - And I'm good, I just need to write to my .cor file!
      * I'm writing the name and comment of course!
      * I need to calculate some parameter encode number (it's just some binary mask)
      * Then I'm writing it directly in a file, for instance if I have a `live %42` I writing to my file : `01 00 00 00 2a` ,`01` being the opcode.
