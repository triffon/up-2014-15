#!/bin/bash

README_TEMPLATE='Задачи от практикум на SHORT_DATE
-------------------------------------------

Тук ще се качват условията и решенията на задачите, дадени на практическите
упражнения на 8. група, провели се на LONG_DATE
'

FIRST_DATE=2014-10-06

for i in {0 .. 10}; do
    date="$(date +%x -d "$FIRST_DATE + $(expr 7 \* $i) day")"
    readme="${README_TEMPLATE/SHORT_DATE/}"
