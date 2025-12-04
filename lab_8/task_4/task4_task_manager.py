import argparse

argparse = argparse.ArgumentParser()

argparse.add_argument("operation", choices=["add", "list", "clear"])
argparse.add_argument("-t", "--text", type=str)

args = argparse.parse_args()

file = "tasks.txt"

if args.operation == "add":
    if args.text is not None:
        with open(file, "a") as file:
            file.write(args.text + "\n")
    else:
        print("add operation requires --text input")

elif args.operation == "list":
    with open(file, "r") as file:
        for index, line in enumerate(file.readlines()):
            print(str(index + 1) + ". " + line.strip("/n"))

elif args.operation == "clear":
    confirm = input("Are you sure? Type yes to confirm: ")

    if confirm == "yes":
        with open(file, "w") as file:
            pass
