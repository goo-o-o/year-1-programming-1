import argparse

argparse = argparse.ArgumentParser()

argparse.add_argument("path", help="Path of file", type=str)
argparse.add_argument("-k", "--keyword", type=str)
argparse.add_argument("-o", "--output", type=str, default="filtered.log")

args = argparse.parse_args()

try:
    filtered_list = []

    with open(args.path, "r") as file:
        for line_number, line in enumerate(file.readlines()):
                if args.keyword in line:
                    output = str(line_number + 1) + " | " + line
                    print(output)
                    filtered_list.append(line)

    if args.output is not None:
        with open(args.output, "a") as file:
            file.writelines(filtered_list)


except FileNotFoundError:
    print("The file " + args.path + " could not be found")