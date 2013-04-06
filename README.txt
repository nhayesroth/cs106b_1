==Problem 1: Rosencrantz and Guildenstern flip Heads (Chapter 2, exercise 15, page 123)

Write a program that simulates flipping a coin repeatedly and continues until three
consecutive heads are tossed. At that point, your program should display the total
number of coin flips that were made.
The following is one possible sample run of the program:

==Problem 2: Obenglobish (Chapter 3, exercise 16, page 152)

Most people—at least those in English-speaking countries—have played the Pig Latin game at some
point in their lives. There are, however, other invented “languages” in which words are created using
some simple transformation of English. One such language is called Obenglobish, in which words are
created by adding the letters ob before the vowels (a, e, i, o, and u) in an English word. For example,
under this rule, the word english gets the letters ob added before the e and the i to form obenglobish,
which is how the language gets its name.
In official Obenglobish, the ob characters are added only before vowels that are pronounced, which
means that a word like game would become gobame rather than gobamobe because the final e is silent.
While it is impossible to implement this rule perfectly, you can do a pretty good job by adopting the
rule that the ob should be added before every vowel in the English word except
• Vowels that follow other vowels
• An e that occurs at the end of the word
Write a function obenglobish that takes an English word and returns its Obenglobish equivalent, using
the translation rule given above.

==Problem 3: Combinations and Pascal's Triangle (Chapter 7, exercise 9, page 349)

As you know from Chapter 2, the mathematical combinations function c(n, k) is usually defined in
terms of factorials, as follows:
c (n , k )= n !
k !(n−k )!
The values of c(n, k) can also be arranged geometrically to form a triangle in which n increases as you
move down the triangle and k increases as you move from left to right. The resulting structure, which
is called Pascal’s Triangle after the French mathematician Blaise Pascal, is arranged like this:
c(0, 0)
c(1, 0) c(1, 1)
c(2, 0) c(2, 1) c(2, 2)
c(3, 0) c(3, 1) c(3, 2) c(3, 3)
c(4, 0) c(4, 1) c(4, 2) c(4, 3) c(4, 4)
Pascal’s Triangle has the interesting property that every entry is the sum of the two entries above it,
except along the left and right edges, where the values are always 1. Consider, for example, the
highlighted entry in the following display of Pascal’s Triangle:
- 3 -
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1
This entry, which corresponds to c(6, 2), is the sum of the two entries—5 and 10—that appear above it
to either side. Using this fact, write a recursive implementation of the c(n, k) function that uses no
loops, no multiplication, and no calls to Fact.
Write a simple test program to demonstrate that your combinations function works. If you want an
additional challenge, write a program that uses c(n, k) to display the first ten rows of Pascal’s
Triangle.

==Problem 4: Implementing Numeric Conversions
The strlib.h interface exports the following methods for converting between integers and strings:
string integerToString(int n);
int stringToInteger(string str);
The first function converts an integer into its representation as a string of decimal digits, so that, for
example, integerToString(1729) should return the string "1729". The second converts in the
opposite direction so that calling stringToInteger("-42") should return the integer -42.
Your job in this problem is to write the functions intToString and stringToInt (the names have
been shortened to avoid having your implementation conflict with the library version) that do the same
thing as their strlib.h counterparts but use a recursive implementation. Fortunately, these functions
have a natural recursive structure because it is easy to break an integer down into two components
using division by 10. This decomposition is discussed on page 42 in the discussion of the digitSum
function. The integer 137, for example, breaks down into two pieces, as follows:
1 3 7
1 3 7
n / 10 n % 10
In other words, you can peel off the last digit of the number n by using division and modulus by 10. If
you use recursion to convert the first part to a string and then append the character value
corresponding to the final digit, you will get the string representing the integer as a whole.
As you work through this problem, you should keep the following points in mind:
• Your solution should operate recursively and should use no iterative constructs such as for or
while. It is also inappropriate to call the provided integerToString function or any other
library function that does numeric conversion.
• The value that you get when you compute n % 10 is an integer, and not a character. To convert
this integer to its character equivalent you have to add the ASCII code for the character '0' and
then cast that value to a char. If you then need to convert that character to a one-character
string, you can concatenate it with string(), as shown here:
string() + ch
If you are coming from Java, be aware that the Java trick of writing
"" + ch
does not work in C++ and will result in very strange behavior – it might return garbage, or just
outright crash the program!
• You should think carefully about what the simple cases need to be. In particular, you should
make sure that calling intToString(0) returns "0" and not the empty string. This fact may
require you to add special code to handle this case.
• Your implementation should allow n to be negative, as illustrated by the earlier example in
which stringToInt("-42") returns -42. Again, implementing these functions for negative
numbers will probably require adding special-case code.
• It's possible to split apart numbers and strings in many ways. You are free to split them
however you'd like. However, peeling off the last digit as we've suggested is easier than most
other approaches.