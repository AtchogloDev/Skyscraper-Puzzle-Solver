# Skyscraper Puzzle Solver v1.1
- First release, v1.0, Thu, 18th Aug 2022, 21:56.
- v1.1, Fr, 16th Sep 2022, 22:20 - .

# Final remarks
- Semi-flexible, ie algo will not successfully work 
if mes is altered;
- A one-week work! Thanks to me for figuring it out!

# Layout

|          | col1up | col2up | col3up | col4up |           |
| -------- | ------ | ------ | ------ | ------ | --------- |
| row1left |   x    |   x    |   x    |   x    | row1right |
| row2left |   x    |   x    |   x    |   x    | row2right |
| row3left |   x    |   x    |   x    |   x    | row3right |
| row4left |   x    |   x    |   x    |   x    | row4right |
|          | col1down | col2down | col3down | col4down |           |

# Views Input Order
./rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right"

# Test running

## Puzzle
![This is the empty test puzzle](https://raw.githubusercontent.com/atchoglogilbert/Skyscraper-Puzzle-Solver/main/puzz_empty.png)

## Commands
```
cd ex00
gcc *.c -o rush-01
./rush-01 "3 2 1 2 1 2 2 3 3 2 2 1 2 1 2 3"
```

## Expected
![This is the filled test puzzle](https://raw.githubusercontent.com/atchoglogilbert/Skyscraper-Puzzle-Solver/main/puzz.png)

## Output
![This is the filled test puzzle](https://raw.githubusercontent.com/atchoglogilbert/Skyscraper-Puzzle-Solver/main/screen.png)
