
import re

with open("input.txt", "r", encoding="utf-8") as f:

    lines = f.readlines()

    acceptable_1 = []
    acceptable_2 = []

    for line in lines:
        rule, password = line.split(":")

        #rule_regex = re.compile(r"")
        rule_count, letter = rule.strip().split()
        rule_min = int(rule_count.strip().split("-")[0])
        rule_max = int(rule_count.strip().split("-")[1])

        password = password.strip()

        c = password.count(letter)

        if c <= rule_max and c >= rule_min:
            acceptable_1.append(password)

        first_idx = password[rule_min-1] == letter
        second_idx = password[rule_max-1] == letter

        if first_idx != second_idx:
            acceptable_2.append(password)


    print("part 1:", len(acceptable_1))
    print("part 2:", len(acceptable_2))

