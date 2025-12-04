import argparse

parser = argparse.ArgumentParser(prog="TemperatureConverter", description="Convert between different temperatures")

parser.add_argument("-val", "--value", type=float)
parser.add_argument("-m", "--mode", choices=["c2f", "f2c"])
parser.add_argument("-r", "--round", type=int, default=2)
parser.add_argument("-ver", "--verbose", type=bool, default=False)

args = parser.parse_args()


def convert_temperature(temp, verbose, mode, round_accuracy):
    if verbose:
        print("Original value: " + str(round(temp, round_accuracy)))
        print("Mode: " + mode)

    if mode == "c2f":
        result = round(temp * 9 / 5 + 32, round_accuracy)

        print("Result: " + str(result))
        # (0°C × 9/5) + 32 = 32°F
    else:
        result = round((temp - 32) * 5 / 9, round_accuracy)

        print("Result: " + str(result))
        # (32°F − 32) × 5/9 = 0°C

convert_temperature(args.value, args.verbose, args.mode, args.round)
