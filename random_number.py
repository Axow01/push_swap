import random
import sys

def generate_random_numbers(count, start, end):
    numbers = random.sample(range(start, end + 1), count)
    return numbers

def main():
    if len(sys.argv) != 4:
        print("Usage: python random_numbers.py <count> <start> <end>")
        return

    try:
        count = int(sys.argv[1])
        start = int(sys.argv[2])
        end = int(sys.argv[3])
    except ValueError:
        print("Error: Count, start, and end must be integers.")
        return

    random_numbers = generate_random_numbers(count, start, end)
    print(' '.join(map(str, random_numbers)))

if __name__ == "__main__":
    main()
