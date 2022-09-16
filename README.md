# Skyscraper Puzzle Solver v1
- First release, v1.0, Thu, 18th Aug 2022, 21:56.
- v1.1, Fr, 16th Sep 2022, 22:20 -

# Final remarks
- Semi-flexible, ie algo will not successfully work 
if mes is altered;
- A one-week work! Thanks to me for figuring it out!

# Test running

## Puzzle
![This is the test puzzle](https://steamuserimages-a.akamaihd.net/ugc/947343292121732592/A6E3950ABFA019E3D5C78A3C202AE6A365FD93C1/)

## Views Input Order (counting from left-right or top-bottom)
./rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right"

## Commands
```
cd ex00
gcc *.c -o rush-01
./rush-01 "3 2 1 2 1 2 2 3 3 2 2 1 2 1 2 3"
```
