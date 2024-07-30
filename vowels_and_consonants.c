#include <stdio.h>
// Write a program in C to count the number of vowels and consonants in a string using a pointer.

int AlphabetCounter(char message[])
{
    int vowel_counter = 0;
    int consonant_counter = 0;
    char *ptr = message;
    int i = 0;
    char vowel[] = {'a', 'e', 'i', 'o', 'u'};
    while (ptr[i] != '\0')
    {
        for (int j = 0; j < 5; j++)
        {
            if (message[i] == vowel[j])
            {
                vowel_counter++;
                break;
            }
                }
        i++;
    }
    printf("Number of consonants: %d", consonant_counter);
    return vowel_counter;
}

int main()
{
    char word[] = "Nigeria";
    int result = AlphabetCounter(word);
    printf("Number of vowels: %d\n", result);
    return 0;
}

/*- *Uppercase letters*:
  - A: 65
  - B: 66
  - C: 67
  - D: 68
  - E: 69
  - F: 70
  - G: 71
  - H: 72
  - I: 73
  - J: 74
  - K: 75
  - L: 76
  - M: 77
  - N: 78
  - O: 79
  - P: 80
  - Q: 81
  - R: 82
  - S: 83
  - T: 84
  - U: 85
  - V: 86
  - W: 87
  - X: 88
  - Y: 89
  - Z: 90

- *Lowercase letters*:
  - a: 97
  - b: 98
  - c: 99
  - d: 100
  - e: 101
  - f: 102
  - g: 103
  - h: 104
  - i: 105
  - j: 106
  - k: 107
  - l: 108
  - m: 109
  - n: 110
  - o: 111
  - p: 112
  - q: 113
  - r: 114
  - s: 115
  - t: 116
  - u: 117
  - v: 118
  - w: 119
  - x: 120
  - y: 121
  - z: 122*/