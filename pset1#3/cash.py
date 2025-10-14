from cs50 import get_float


def main():
    while True:
        dollars = get_float("Change owed: ")
        if dollars >= 0:
            break

    cents = round(dollars * 100)

    quarters = cents // 25
    cents %= 25

    dimes = cents // 10
    cents %= 10

    nickels = cents // 5
    cents %= 5

    pennies = cents  # remaining value of cents is updated to pennies

    total_coins = quarters + dimes + nickels + pennies

    print(total_coins)


if __name__ == "__main__":  # defining main()
    main()
