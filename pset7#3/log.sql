-- Keep a log of any SQL queries you execute as you solve the mystery.

-- July 28th on Humphrey Steet at 10:15am. Interviews were conducted with 3 witnesses all mentioning the bakery.
-- Littering took place at 16:36
-- in order to get the description of the crime scene:
SELECT *
FROM  crime_scene_reports
WHERE month = 7
      AND day = 28
      AND street = 'Humphrey Street';

-- acquiring more information about the witnesses who mentioned the bakery:
SELECT *
FROM interviews
WHERE year = 2023
      AND month = 7
      AND day = 28
      AND transcript LIKE '%bakery%';

-- ruth: theif's car parked in bakery parking lot
-- eugene: theif withdrawing money at the ATM on Leggett Street
-- raymond: called accomplice after to purchase earliest flight tickets out of fiftyville. around 10:25 + talked for <1min

-- investigating ruth's claim:
SELECT *
FROM bakery_security_logs
WHERE year = 2023
      AND month = 7
      AND day = 28
      AND hour = 10;

-- matching the license plates to people's names:
SELECT bsl.license_plate,
       bsl.month,
       bsl.year,
       bsl.day,
       bsl.hour,
       p.name
FROM   people p
       JOIN bakery_security_logs bsl
       ON p.license_plate = bsl.license_plate
       WHERE year = 2023
             AND month = 7
             AND day = 28
             AND hour = 10;
-- potential thief: vanessa, bruce, barry, luca, sofia, iman, diana

-- investigating eugene's claim:
SELECT *
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
      AND year = 2023
      AND month = 7
      AND day = 28
      AND transaction_type = 'withdraw';

-- matching account number to people's names:
SELECT at.account_number,
       at.year,
       at.month,
       at.day,
       p.name
FROM atm_transactions at
     JOIN bank_accounts ba
       ON at.account_number = ba.account_number
     JOIN people p
       ON p.id = ba.person_id
WHERE atm_location = 'Leggett Street'
      AND year = 2023
      AND month = 7
      AND day = 28
      AND transaction_type = 'withdraw';
-- names: Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista
-- vanessa x, barry x, sofia x, benista x, taylor x, kenny x, brooke x
-- either bruce, diana, or luca

-- investigating raymond's claim:
SELECT pc.caller,
       pc.receiver,
       pc.duration,
       p.name
FROM phone_calls pc
     JOIN people p
       ON pc.receiver = p.phone_number
WHERE pc.year = 2023
      AND pc.month = 7
      AND pc.day = 28
      AND pc.duration <= 60;
-- luca x, either bruce or diana

SELECT *
FROM airports; -- id no.of fiftyville airport = 8

SELECT *
FROM flights f
     JOIN airports
       ON f.destination_airport_id = airports.id
WHERE year = 2023
      AND month = 7
      AND day = 29;

-- fiftyville to LaGuardia Airport in NYC + flight id = 36

SELECT p.passport_number,
       people.name
FROM passengers p
     JOIN people
       ON p.passport_number = people.passport_number
WHERE flight_id = 36;
-- theif name: Bruce

SELECT pc.receiver,
       p1.name
FROM phone_calls pc
     JOIN people p1
       ON pc.receiver = p1.phone_number
     JOIN people p2
       ON pc.caller = p2.phone_number
WHERE pc.year = 2023
      AND pc.month = 7
      AND pc.day = 28
      AND pc.duration <= 60
      AND p2.name = 'Bruce';
-- accomplice name: Robin
