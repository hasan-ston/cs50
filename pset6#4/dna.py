import csv
import sys

database = [] # to store rows from CSV file

def main():
    # Check for command-line usage
    if len(sys.argv) < 2:
        sys.exit("Pass in an argument")

    # Read database file into a variable
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row) # append each row to database file

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file: #3rd cmd line argument
        dna_seq = file.read().strip()

    strs = list(database[0].keys())[1:]  # skipping the first column 'name'

    # Find longest match of each STR in DNA sequence
    str_counts = {} #empty dict
    for str in strs:
        str_counts[str] = longest_match(dna_seq, str)

    # Check database for matching profiles
    for person in database:
        match = True
        for str in strs:
            if int(person[str]) != str_counts[str]:
                match = False
                break
        if match:
            print(person['name'])
            return

    print("no match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            start = i + count * subsequence_length # calculating starting index
            end = start + subsequence_length       # calculating ending index

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run

main()
