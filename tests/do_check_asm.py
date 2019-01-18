import os, filecmp

print("----- >> DIFF CHECKER ASM << -----\n")

for file in os.listdir("./examples"):
    if file.endswith(".s"):
        print("->> " + file + " <--")
        name = os.path.splitext(file)[0]
        os.system("./my_asm ./examples/" + file)
        os.system("cp ./examples/" + name + '.cor ./my_cor/')
        os.system("./zaz_asm ./examples/" + file)
        os.system("cp ./examples/" + name + '.cor ./zaz_cor/')

print("\n")

for file in os.listdir("./my_cor"):
    for files in os.listdir("./zaz_cor"):
        if (file == files):
            os.system("diff ./zaz_cor/" + files + " ./my_cor/" + file)

print("No output ? Good news ;)")
os.system("rm examples/*.cor")
