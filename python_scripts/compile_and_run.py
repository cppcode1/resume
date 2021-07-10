"""
this python script compiles and run .cpp files and cleans up at the end
Oleksandr Chastukhin
"""
from sys import argv as files
import os

only_this_script = 1
objects = []

if len(files) == only_this_script:
    print("there is no passed arguments except this script")
    exit(0)

def analize_file_name(file):
    file_parts = file.split(".")
    parts_count = len(file_parts) 

    no_extention = True if parts_count == 1 else False
    too_much_dots = True if parts_count > 2 else False

    if no_extention:
        print(f"the file \'{file}\' have no extention")
        exit(0)
    
    file_name = file_parts[0]
    file_extention = file_parts[parts_count - 1]
    return (file_name, file_extention)

def clean():
    os.system("rm -f *.o")
    os.system("rm -f app")

clean()

# compile all files save this *.py script
for file in files[1:]:
    name, extention = analize_file_name(file)
    print(name, extention)
    if extention == "cpp":
        os.system(f"g++ -c {file}")
        objects.append(f"{name}.o")
    else:
        objects.append(file)
    
# compile the app
objects_list = ' '.join(objects)
print(objects_list)
os.system(f"g++ -g -std=c++17 -o app {objects_list}")

# and fire up the app
os.system("clear")
os.system("ls -l app")
print("fire up the app")
os.system("./app")
clean()
print("done")


