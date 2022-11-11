# Push_swap
**push_swap** is a C language program that takes a random number as a argument, and sort those numbers on a stack with a limited set of instructions.

you can read the subject [here](https://github.com/fpetras/42-subjects/blob/master/push_swap.en.pdf)

## Quick Demo

- 100 numbers

![title](https://user-images.githubusercontent.com/108667563/201254024-b0b43797-d4a7-4472-88eb-64419df62f5d.gif)

- 500 numbers

![title](https://user-images.githubusercontent.com/108667563/201254583-6fc167bb-d89e-4a39-822c-1bcbadbf6927.gif)

Using **push_swap_visualizer** from [here](https://github.com/o-reo/push_swap_visualizer)

# Description
The goal of this project is to sort `stack A` with random numbers using empty `stack B` and given instructions.
You have to minimize your instructions as much as you can.
- parse arguments of string based random numbers and   convert to integer.
- numbers can be any signed integer values, without duplicates.
- sort numbers using given set of instructions with various algorithm.
- the final result must be sorted `stack A` and empty `stack B`.
- the sequence of instructions used to sort need to be written to `STDOUT`.
## Instructions
- **push**
    - Notation: `pa (b→a)`, `pb(a→b)`
    - Take the first element at top of `stack x` and put it at top of `another stack`.
- **swap**
    - Notation: `sa`, `sb`, `ss(sa + sb)`
    - Swap the first 2 elements at top of `stack x`.
- **rotate**
    - Notation: `ra`, `rb`, `rr(ra + rb)`
    - Shift up all elements of `stack x` by 1, the first element becomes the last one.
- **reverse rotate**
    - Notation: `rra`, `rrb`, `rrr(rra + rrb)`
    - Shift down all elements of `stack x` by 1, the last element becomes the first one.

# Ideas
**Data Structure**
- Store parsed numbers using **doubly linked list** instead of stack data structure, so it could be easier to implement rotate instruction.

**Preprocessing**
- Copy stored random numbers to temp array and sort the array using insertion sort.
- Set four pivot to make a equal five-part division.
- Circulate `stack A` and push two division part to `stack B` using instructions.
    - the smallest numbers divison goes to `stack B` top side using `pb()`.
    - next divison goes to `stack B` bottom side using `pb() → rb()`.
    - rest of the divison parts pile up again in `stack A` using `ra()`.
    - when the circulation is over, push last divison part to `stack B`.

![title](https://user-images.githubusercontent.com/108667563/201289123-6348d0a1-90c3-413b-a080-155a58268ad6.png)   

**Greedy Algorithm**
- Calculate the number of instructions that can push selected number to `stack A` in order.
    - `stack A` ordered form could be like `1, 2, 3, 4, 5` and also `4, 5, 1, 2, 3`.
- Caculate the number if instructions for all elements of `stack B` and find the number with the least instructions.
- Rotate `stack A` and `stack B`. If rotate direction is same, replace both `stack A` and `stack B` instructions to `rr()` or `rrr()`.
- Using `pa()` instruction to push `stack B` top number to `stack A`.
- Repeat this process until `stack B` is empty.
- Rearrange `stack A` to raise the smallest number to top.

```c
while (list_b->size != 0)
	{
		set_rotate_info(&rotate_info, list_a, list_b);
		rotate_list_ab(&rotate_info, list_a, list_b);
		pa(list_b, list_a);
	}
	align_list_a(list_a);
```

## Algorithm Performance
- **100 numbers**
    - AVG: 575
    - MAX: 675
- **500 numbers**
    - AVG: 4019
    - MAX: 4464
- **1000 numbers**
    - AVG: 9623
    - MAX: 10469

# Compilation
```sh
$ git cone https://github.com/gerry-mandering/push_swap-c.git
$ cd push_swap-c
$ make all
```

Make `./checker`
```sh
$ make bonus
```

## Usage
Give **random numbers** to `./push_swap` using command line arguments.
```sh
$ ./push_swap 5 -1 1 3 4 7 -3 0

$ ARG="13 -3 -63 7 2"; ./push_swap $ARG

$ ARGS=`seq 100 | sort -R | xargs`; ./push_swap $ARGS
```

Check written instructions ouptput using `./checker`.
```sh
$ ARG="13 -3 -63 7 2"; ./push_swap $ARG | ./checker_OS $ARG

$ ARGS=`seq 100 | sort -R | xargs`; ./push_swap $ARGS | ./checker $ARGS
```
## Directory Tree
<details>
<summary>Directory Tree</summary>
<pre>
.
├── Makefile
├── README.md
├── bonus
│   ├── includes
│   │   └── checker_bonus.h
│   └── src
│       ├── checker_bonus.c
│       ├── checker_utils
│       │   ├── execute_commands_bonus.c
│       │   └── validate_list_ab_bonus.c
│       ├── list_command
│       │   ├── list_basic_bonus.c
│       │   ├── list_clear_bonus.c
│       │   ├── list_command_push_bonus.c
│       │   ├── list_command_reverse_rotate_bonus.c
│       │   ├── list_command_rotate_bonus.c
│       │   ├── list_command_swap_bonus.c
│       │   └── list_push_pop_bonus.c
│       ├── list_util
│       │   └── is_sorted_bonus.c
│       └── parse
│           ├── parse_arguments_bonus.c
│           └── parse_commands_bonus.c
├── includes
│   └── push_swap.h
├── library
│   ├── ft_printf-c
│   ├── get_next_line-c
│   └── libft-c
└── src
    ├── greedy_sort
    │   ├── align_list_a.c
    │   ├── get_min_max.c
    │   ├── greedy_sort.c
    │   ├── rotate_list_ab.c
    │   ├── set_list_a_rotate.c
    │   ├── set_list_b_rotate.c
    │   ├── set_rotate_info.c
    │   └── sort_with_greedy_algorithm.c
    ├── list_command
    │   ├── list_basic.c
    │   ├── list_clear.c
    │   ├── list_command_push.c
    │   ├── list_command_reverse_rotate.c
    │   ├── list_command_rotate.c
    │   ├── list_command_swap.c
    │   └── list_push_pop.c
    ├── list_util
    │   └── is_sorted.c
    ├── parse_arguments
    │   └── parse_arguments.c
    ├── predefined_logic
    │   ├── predefined_logic_utils.c
    │   └── sort_with_predefined_logic.c
    ├── push_swap.c
    └── sort_array
        └── sort_array.c
</pre>
</details>
