/*
Sometimes some words like "localization" or "internationalization" are so long that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10 characters. All too long words should be replaced with a special abbreviation.

This abbreviation is made like this: we write down the first and the last letter of a word and between them we write the number of letters between the first and the last letters. That number is in decimal system and doesn't contain any leading zeroes.

Thus, "localization" will be spelt as "l10n", and "internationalization» will be spelt as "i18n".

You are suggested to automatize the process of changing the words with abbreviations. At that all too long words should be replaced by the abbreviation and the words that are not too long should not undergo any changes.

Input
The first line contains an integer n (1 ≤ n ≤ 100). Each of the following n lines contains one word. All the words consist of lowercase Latin letters and possess the lengths of from 1 to 100 characters.

Output
Print n lines. The i-th line should contain the result of replacing of the i-th word from the input data.

Examples
InputCopy
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis
OutputCopy
word
l10n
i18n
p43s
*/

#include <iostream>
#include <string>
#include <vector>

std::string shorten(std::string word){
    int size = word.length();
    //// If the word length is 10 or less, return it as is
    if(size <= 10){
        return word;
    }

    if(size <= 100){
          // Prepare final string with first character
    std::string finalString;
    finalString = word[0];

     // Count the inner characters (size - 2)
    int innerLetterCount = size - 2;
      
    // Add innerLetterCount and the last character to the final string
    finalString += std::to_string(innerLetterCount);
    finalString += word[size - 1];

        
    return finalString;
    }
}

int main(){
    std::string result = shorten("Dog");
    std::cout << result << std::endl;

    result = shorten("Internationalization");
    std::cout << result << std::endl; 

     result = shorten("pneumonoultramicroscopicsilicovolcanoconiosis");
    std::cout << result << std::endl;  
}