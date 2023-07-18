


# Learn C Programming - Second Edition

<a href="https://www.packtpub.com/product/learn-c-programming-second-edition/9781801078450?utm_source=github&utm_medium=repository&utm_campaign=9781801078450"><img src="https://static.packt-cdn.com/products/9781801078450/cover/smaller" alt="Learn C Programming - Second Edition" height="256px" align="right"></a>

This is the code repository for [Learn C Programming - Second Edition](https://www.packtpub.com/product/learn-c-programming-second-edition/9781801078450?utm_source=github&utm_medium=repository&utm_campaign=9781801078450), published by Packt.

**A beginner's guide to learning the most powerful and general-purpose programming language with ease**

## What is this book about?
The foundation for many modern programming languages such as C++, C#, JavaScript, and Go, C is widely used as a system programming language as well as for embedded systems and high-performance computing. With this book, you'll be able to get up to speed with C in no time. 

This book covers the following exciting features:
* Implement fundamental programming concepts through C programs
* Understand the importance of creating complex data types and the functions to manipulate them
* Develop good coding practices and learn to write clean code
* Validate your programs before developing them further
* Use the C Standard Library functions and understand why it is advantageous
* Build and run a multi-file program with Make
* Get an overview of how C has changed since its introduction and where it is going

If you feel this book is for you, get your [copy](https://www.amazon.com/dp/1801078459) today!

<a href="https://www.packtpub.com/?utm_source=github&utm_medium=banner&utm_campaign=GitHubBanner"><img src="https://raw.githubusercontent.com/PacktPublishing/GitHub/master/GitHub.png" 
alt="https://www.packtpub.com/" border="5" /></a>

## Errata

* **Page 57:** The sentences
  > The set of values a byte can represent is 256 or [28]() values. These values range from 0 to 255 or [28–1](). 0 is a value that must be represented in the set of 256 values; we can't leave that value out. A byte can either represent a positive integer ranging from 0 to 255, or [28–1](), or a negative integer ranging from -128 to 127.

  leave out proper superscripts. They should be
  > The set of values a byte can represent is 256 or [2<sup>8</sup>]() values. These values range from 0 to 255 or [2<sup>8</sup>–1](). 0 is a value that must be represented in the set of 256 values; we can't leave that value out. A byte can either represent a positive integer ranging from 0 to 255, or [2<sup>8</sup>–1](), or a negative integer ranging from -128 to 127.

* **Page 62:** The term
  > significand x [baseexponent]()
  
  leaves out proper superscripting. It should appear as
  > significand x [base<sup>exponent</sup>]()

* **Page 113:** At the bottom of the page, the declaration of constant values are missing the assignment operator (=). They should be declared as:
  
        const unsigned char lowercase = 1;
        const unsigned char bold      = 2;
        const unsigned char italic    = 4;
        const unsigned char underline = 8;

* **Page 121:** The wrong table has been displayed for *Table 5.1 – Operator precedence table*.<br>
The correct Operator precedence table may be found on Page 660.

* **Page 229:** In the 3rd paragraph, the sentence should be:
  > The C compiler does not see any difference between a variable and constant variable [after]() they have been declared.

* **Page 230:** The next to last paragraph should read
  > All the values of each array are initialized to 0 when the value given within `{` and `}` is 0, 
as in `int a[5] = {0};` otherwise the values are assigned in the sequence given within `{` and `}`, 
as in `int b[5] = { 5 , 4 , 3 , 2 , 1 }`. Only the values given will initialize the corresponding elements; so,
  >  `int c[5] = { 5 , 4 };` only initialized the first two elements and the remaining elements are unintialized.

* **Page 252:** The initialization shown for `array3D` is for a 3 x 2 x 5 array.<br>
The initialization for a 3 x 4 x 5 array should appear as

        int array3D[size3d][size2D][size1D] = 
          { { { 111 , 112 , 113 , 114 , 115 },
              { 121 , 122 , 123 , 124 , 125 }, 
              { 131 , 132 , 133 , 134 , 135 },
              { 141 , 142 , 143 , 144 , 145 } },
            { { 211 , 212 , 213 , 214 , 215 },
              { 221 , 222 , 223 , 224 , 225 }, 
              { 231 , 232 , 233 , 234 , 235 },
              { 241 , 242 , 243 , 244 , 245 } },
            { { 311 , 312 , 313 , 314 , 315 },
              { 321 , 322 , 323 , 324 , 325 }, 
              { 331 , 332 , 333 , 334 , 335 },
              { 341 , 342 , 343 , 344 , 345 } } };

* **Page 447:** In the first code snippet, the text 
  > `The second is as follows:`
  
  is shown as source code but it is not. It should be shown as descriptive text:
  > The second is as follows:

* **Page 463:** In the table output for `unsignedIn.c`, "HEX[I]()DECIMAL" should be "HEX[A]()DECIMAL"

* **Page 489:** In the table, the cell in the 4th row and 5th column incorrectly shows
  > [scanf()]()

  when it should be
  > [sscanf()]()

* **Page 504:** In the 3rd paragraph, it reads
  > The following program reads a group of digits, each of which is intended to represent a date—[the first four digits for the year, the next two for the month, and the last two for the day]():
  
  This should read
  > The following program reads a group of digits, each of which is intended to represent a date—[the first two digits for the month, the next two for the day and the last four digits for the year]():



## Instructions and Navigations
All of the code is organized into folders. For example, Chapter02.

The code will look like the following:
```
#include <stdio.h>

int main( void )  {
  printf( "Hello, world!\n" );
  return 0;
}
```

**Following is what you need for this book:**
If you're an absolute beginner who has basic familiarity with operating a computer, this book will help you learn the most fundamental concepts and practices that you need to know to become a successful C programmer. If you're an experienced programmer, you'll find the full range of C syntax as well as common C idioms covered in the book useful.

With the following software and hardware list you can run all code files present in the book (Chapter 1-27).
### Software and Hardware List
| Chapter | Software required | OS required |
| -------- | ------------------------------------ | ----------------------------------- |
| 1-27 | GCC | Windows, Mac OS X, and Linux (Any) |

We also provide a PDF file that has color images of the screenshots/diagrams used in this book. [Click here to download it](https://packt.link/uDSeu).

### Related products
* Expert C++ [[Packt]](https://www.packt.com/product/programming/b13597-expert-c/?utm_source=github&utm_medium=repository&utm_campaign=9781801073240) [[Amazon]](https://www.amazon.com/dp/1838552650)

* C++20 STL Cookbook [[Packt]](https://www.packt.com/product/programming/b18267-c-20-stl-cookbook/?utm_source=github&utm_medium=repository&utm_campaign=9781800568754) [[Amazon]](https://www.amazon.com/dp/1803248718)

## Get to Know the Author
**Jeff Szuhay**
is the principal developer at QuarterTil2 which specializes in graphics-rich software chronographs for desktop environments. In his software career of over 35 years, he has engaged in a full range of development activities from systems analysis and systems performance tuning to application design, from initial development through full testing and final delivery. Throughout that time, he has taught computer applications and programming languages at various educational levels from elementary school students to university students, as well as developed and presented professional, on-site training.
### Download a free PDF

 <i>If you have already purchased a print or Kindle version of this book, you can get a DRM-free PDF version at no cost.<br>Simply click on the link to claim your free PDF.</i>
<p align="center"> <a href="https://packt.link/free-ebook/9781801078450">https://packt.link/free-ebook/9781801078450 </a> </p>
