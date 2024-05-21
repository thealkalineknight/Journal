# conclude and move to ray
# the thing is that movement is rigged for a ray game, not pong. don't dally here.
# you would just tear everything down and insert old pin pon
# basically, you learned how to manipulate the map, player, and rays through colvars etc.
# take a look at the commented out ray draws!
# ray casting will be used for future game special effects flying objects and paddles
# special effects are static and animated sprites


# notes:

# map.py; get map puts diff blocks in diff dicts but all in world
# if player collide, then split block (by colvar) for each hit

# player.py; suppose colvar = 0.25, get empty dist, 0.75. get % 1 of player cor and former < latter

# ray.py; get empty colvar, then add to move-able space

# paddle.py max lim does not scale with pad height (and that's okay because we're moving on)
