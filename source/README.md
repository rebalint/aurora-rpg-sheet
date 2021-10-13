# TODO LIST

- add [name]|[description] option for text properties in race loader

- add race, classes, magic, etc
- add ferin and elder race traits
- add UI for race, class and magic
- add text-only properties to character (like char description)
- save+load
- make everything responsive and tidy up UI in general

- add proper readme
- transfer in-line to-dos here if needed

- add more testing

# Race, PClass, magic

read from file

## Race

### Loader

loader in character loads file 1, which contains descriptions of general abilities, etc (like wp, hp, body), uses these to set description field for them based on name

loader loads races.txt, containing races
    - first line is the number of races
    
    - subraces are also implemented as races, with a `subraceof` field
    fields:
        - separator: | for inline stuff, newline between properties
        - RACE [number of properties belonging to the class]
        
        - name
        - description
        
        - subraceof (`none` if not a subrace)

        - array of properties
            - SCORE [varname/anyskill/anyability OR varname1/varname2] [MOD/SET] [num] format for modifiers (incl. speed)
            - TEXT [desc] or text-based traits, size, etc
            - CLASS [SET/NOT] classname


Ferin: basic race entry, check if  it's ferin if/when race is loaded, set up custom stuff

Elder race: same thing, only handle it after ch.race has been set

EXAMPLE RACE ENTRY:
```
RACE 5
Storm elf|Storm elves are typically shorter and stockier with less pronounced tapered ears. The skin of storm elves resembles mottled gray skies, and their hair is typically a pale yellow or blue.
subraceof Elf
TEXT Your size is medium.
SCORE mind MOD +2
SCORE connection/nimble MOD +1
SCORE perception MOD +1
SCORE speed MOD +2
```

### Adding race to character

select via ui somehow

###  RaceUI



## Class

read from file

# TESTING

using GTest

in order to use, download googletest source and link it in testing/gtest_dependency.pri by adding:
```
GOOGLETEST_DIR = [gtest source]/googletest
```

# NOTES

tab widget to change between view/edit of race, class and spells

TODO: if implemented in rulebook, allow races to add spells to character
