# Simpletron Machine Language (SML)

The Simpletron runs programs written in the only language it directly understands: Simpletron Machine Language (SML).

## Commands

| Value | Description |
|-------|-------------|
| 10    | Read a word from the keyboard into a specific location in memory. |
| 11    | Write a word from a specific location in memory to the screen. |
| 20    | Load a word from a specific location in memory into the accumulator. |
| 21    | Store a word from the accumulator into a specific location in memory. |
| 30    | Add a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator). |
| 31    | Subtract a word from a specific location in memory from the word in the accumulator (leave the result in the accumulator). |
| 32    | Divide a word from a specific location in memory into the word in the accumulator (leave result in the accumulator). |
| 33    | Multiply a word from a specific location in memory by the word in the accumulator (leave the result in the accumulator). |
| 40    | Branch to a specific location in memory. |
| 41    | Branch to a specific location in memory if the accumulator is negative. |
| 42    | Branch to a specific location in memory if the accumulator is zero. |
| 43    | Halt. The program has completed its task. |

## Installation

You can use git to clone the repository

```bash
git clone https://github.com/arthurbrenno/simpletron-machine-language.git
```
Or just download it as a .zip

Code ---> Download zip


## Executing
You can Execute by compiling and opening the .exe at
```bash
...\x64\Debug\Simpletron.exe
```


## Contributing

Pull requests are always welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
