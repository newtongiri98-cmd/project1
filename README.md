reedit readme we just add map navigation link on project graphic is pending 

```markdown
# Smart Bus Route & Fare Finder

A C-based console application that helps users find bus routes between stations in the Kathmandu Valley. The system supports direct routes, transfer routes, and fare calculation with discount options based on user category.

## Project Overview

This project simulates a basic transport route system. Users enter a source and destination, and the program finds available bus routes. If a direct route is not available, it searches for a transfer route. The program also calculates fare and applies discounts for different user categories.


## Project Submission Details

Submitted by: Nabin Giri (nabin_5400)
College: Kuleshwor Awas Campus, Kathmandu, Nepal
Department: Department of Science
Program: Bachelor of Information Technology (BIT)
Semester: 1st Semester
Subject: C Programming
Subject Teacher: Ojan Adhikari
Program Director: Narayan GC
Year: 2026

## Versions

### Version 1.0

The first version of the project focused on basic functionality.

Features:

* Find direct bus routes between two stations
* Support for single transfer route if direct route is not available
* Student discount using simple yes/no input
* Basic fare display

Limitations:

* Only one bus shown per route
* One-way matching only
* No proper user categories
* No structured output format
* Limited flexibility in route selection


### Version 1.1

This version improves the structure, logic, and user experience.

Improvements and Features:

* Multiple bus options are displayed for the same route
* Users can select preferred bus service from a list
* Added user category system:

  * Old Age (30% discount)
  * Student (35% discount)
  * Normal (no discount)
* Bidirectional route matching (both directions supported)
* Transfer route support improved with step-by-step output
* Structured fare summary showing full breakdown
* Improved input handling and validation

## How to Run

Compile and run using GCC:

```bash
gcc fare.c -o fare
./fare
```


## Sample Output

```
Smart Bus Route Finder

Enter source station     : kalanki
Enter destination station: koteshwor

Available Yatayat:
[1] Metropolitan Yatayat
[2] Sajha Yatayat
[3] Chakrapath Yatayat

Select yatayat (1-3): 2

Select your category:
[1] Old Age (30% discount)
[2] Student (35% discount)
[3] Normal (no discount)

Enter choice (1-3): 2

Fare Summary
Source      : kalanki
Destination : koteshwor
Yatayat     : sajha yatayat
Base Fare   : Rs. 40
Category    : Student
Discount    : Rs. 14
Final Fare  : Rs. 26
```

---

## Route Coverage

| Yatayat              | Route                          |
| -------------------- | ------------------------------ |
| Kirtipur Yatayat     | Kirtipur to Sundhara area      |
| Rara Hill Yatayat    | Rara Hill to Balkhu / Sundhara |
| Metropolitan Yatayat | Kalanki to Koteshwor           |
| Sajha Yatayat        | Kalanki to Koteshwor           |
| Chakrapath Yatayat   | Kalanki to Koteshwor           |
| Bhaktapur Yatayat    | Koteshwor to Bhaktapur         |

---

## Technologies Used

* C Programming Language
* GCC Compiler
* Standard C libraries only (stdio.h, string.h, ctype.h, stdlib.h)

---

## Key Concepts

* Structures
* Arrays
* String handling
* Linear search
* Nested loops
* Case-insensitive comparison
* Modular function design