# KaboomBoyAgent
First Agent for Kaboom Boy

## Rules

The idea is that the agent acts accordingly to a set of simple rules, of decreasing importance. Effectively, each turn, the agent first considers which moves are available to it by the board. For instance, the agent cannot move into a wall, obstacle or bomb. The rules are applied in order. If, at any point during applying the rules, only one available move (other than 'wait') is left, this move will be executed and further rules will not be considered. If, after applying all rules, multiple moves remain possible, a random choice is made. The moves that are available to it are then culled by the following rules:

Note that each rule can be applied indepently of one another and that the order can be dynamically switched around. Each rule will be implemented as an independent behavioural pattern.

### Rule 1: Don't Die

The first rule calculates all moves that lead to inevitable death. This rule can become rather complicated in theory, but in practice it probably will consider inevitable death as nearing an existing bomb in such a way that there are insufficient turns left to run away. 

### Rule 2: KILL

If the agent considers that there is sufficent likelihood (to be defined) that planting a bomb leads to another agent's death, then what are you waiting for!

### Rule 3: SEEK AND DESTROY

If a path is available to the agent that leads it to another agent, then it will approach that agent in an effort to kill it.

### Rule 4: Clear a path

If destructible obstacles can be destroyed by placing a bomb here, then place a damn bomb!

### Rule 5: Find an obstacle

Find a good destructible obstacle to blow up!

### Last Rule: Follow Thee Path

If the agent still doesn't know what to do, at the very least it won't go back where it came from. We'll persist, after all!


