/**
-- Hashing: O(1) search,insert, delete on average and o(n) for worst case if all items hash to the 
    same bucket
-- Hash table by general is an unordered data strucutre
-- Array has great cache locality(CPU loads nearby memory together), Hash table has poor cache
    locality(jumping around random memory locations)
-- CPU cache is "spatial locality" based - it assumes if you access one memory location, you will 
    likely access nearby locations soon.
-- Hash table is used in  most of the algorithms: arrays, linkedlist, graph , dp algorithms
-- Restaurant menu look up for an item is O(N), ask waiter it will become O(1), add new item or delete
out of order item, that should be O(1)

 */
