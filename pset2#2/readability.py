from cs50 import get_string


def count_letters(text):
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    return letters


def count_words(text):
    end_word = text.split()
    num_word = len(end_word)
    return num_word


def count_sentences(text):
    end_sentence = [".", "!", "?"]
    num_sentence = 0
    for char in text:
        if char in end_sentence:
            num_sentence += 1
    return num_sentence


def cl_formula(letters, words, sentences):
    L = letters / words * 100
    S = sentences / words * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


def main():
    text = get_string("Text: ")
    num_letters = count_letters(text)
    num_words = count_words(text)
    num_sentences = count_sentences(text)

    grade_level = cl_formula(num_letters, num_words, num_sentences)

    if grade_level > 16:
        print("Grade 16+")
    elif grade_level < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade_level}")


if __name__ == "__main__":
    main()
