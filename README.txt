       _                           _                   
      | |                         | |                  
   ___| | ___ _ __ ___   ___ _ __ | |_ __ _ _ __ _   _ 
  / _ \ |/ _ \ '_ ` _ \ / _ \ '_ \| __/ _` | '__| | | |
 |  __/ |  __/ | | | | |  __/ | | | || (_| | |  | |_| |
  \___|_|\___|_| |_| |_|\___|_| |_|\__\__,_|_|   \__, |
          | | |                                   __/ |
   ___ ___| | |_   _  __ _ _ __                  |___/ 
  / __/ _ \ | | | | |/ _` | '__|                       
 | (_|  __/ | | |_| | (_| | |                          
  \___\___|_|_|\__,_|\__,_|_|          _               
             | |                      | |              
   __ _ _   _| |_ ___  _ __ ___   __ _| |_ __ _        
  / _` | | | | __/ _ \| '_ ` _ \ / _` | __/ _` |       
 | (_| | |_| | || (_) | | | | | | (_| | || (_| |       
  \__,_|\__,_|\__\___/|_| |_| |_|\__,_|\__\__,_|       
                                                 
https://en.wikipedia.org/wiki/Elementary_cellular_automaton
Inspired by https://web.archive.org/web/20210625032346/https://spaciecat.github.io/cells/

This is a collection of programs designed to emulate every possible elementary cellular automaton.
It contains the development procession of the script, the final version, and two smaller functions that were useful in developing the larger script.

Initially designed to solely emulate the Turing-complete rule 124 (a mirror of the more well-known rule 110), this was scoped up to be able to emulate any of the 256 possible rulesets.
Live cells are represented with an X; dead cells are represented with a space.

Features:
Minimizes dead space: if the rule does not go left or right of the initial mark, those squares are not printed (compare rules 2 and 16)
Uses millisecond-level precision in the introduction
Editable initial seed

Developed from December 21 to December 31 2022
