import argparse
import csv

argparse = argparse.ArgumentParser()

argparse.add_argument("path", type=str)
argparse.add_argument("-c", "--category", type=str)
argparse.add_argument("-m", "--minimum_amount", type=float)
argparse.add_argument("-o", "--output", action="store_true")

args = argparse.parse_args()

with open(args.path, mode="r", newline='') as file:
    csv_reader = csv.DictReader(file)
    output = []
    total_amount = 0
    for row in csv_reader:
        flag = True

        if args.category is not None:
            flag = flag and (row["category"] == args.category)

        if args.minimum_amount is not None:
            flag = flag and (float(row["amount"]) >= args.minimum_amount)

        if flag:
            total_amount += float(row["amount"])
            output.append(row)

if args.output:
    with open("filtered.csv", mode="w", newline='') as file:
        writer = csv.DictWriter(file, fieldnames=output[0].keys())
        writer.writeheader()
        writer.writerows(output)

for row in output:
    print(f'{row["date"]} - {row["category"]} - RM{row["amount"]}')

print("Total records: " + str(len(output)))
print(f'Total amount: RM{total_amount:.2f}')
print(f'Average amount: RM{total_amount / len(output):.2f}')
