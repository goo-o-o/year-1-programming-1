import argparse

argparse = argparse.ArgumentParser()

argparse.add_argument("duration", help="Duration in minutes", type=float)
argparse.add_argument("-s", "--subjects", nargs="+", type=str)
argparse.add_argument("-b", "--break_interval", default=25, type=float)
argparse.add_argument("-q", "--summary", action="store_true")

args = argparse.parse_args()

each = args.duration / len(args.subjects)
if args.summary:
    print("Total Time: " + str(args.duration))
    print("Subjects: " + str(len(args.subjects)))
    print("Breaks: " + str(len(args.subjects)))

else:
    print("Study Schedule:")
    for i, entry in enumerate(args.subjects):
        print(str(i + 1) + ". " + entry + ": " + str(each) + " minutes")