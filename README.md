# ListeningComprehensionGradeEvaluator

## Introduction

This helps to evaluate your CET 4 listening comprehension grades easily when preparing for the exam.

## Usage:

Prepare a data file named `data.txt` in the same directory as the executable with the first line your answers and the second line the correct answers, split by a space every five entities. ( You can also add another line indicating whether you'd like a detailed analysis, 1 for true and 0 for false)

```
ABCAB ADDAC ACBCB ADDCA DBADB
ACCAD ADDBC ADBCB ADCCA BDADD
1
```

This will give you the following outputs:

```
You got 163.3 (65.7%) scores.
Details:
        ----------
2. C. Actual: B (-7.1 scores.)
5. D. Actual: B (-7.1 scores.)
9. B. Actual: A (-7.1 scores.)
12. D. Actual: C (-7.1 scores.)
18. C. Actual: D (-14.2 scores.)
21. B. Actual: D (-14.2 scores.)
22. D. Actual: B (-14.2 scores.)
25. D. Actual: B (-14.2 scores.)
        ----------
```

Or if you don't like the analysis

```
ABCAB ADDAC ACBCB ADDCA DBADB
ACCAD ADDBC ADBCB ADCCA BDADD
0
```

which gives you

```
You got 163.3 (65.7%) scores.
Analysis is OFF.
```

## Why this?

You can listening to the materials over and over again until you solve all the problems without looking at the answers every time you're finished. (This reduces the change you unintentionally memorized the correct answers while comparing them with yours.)