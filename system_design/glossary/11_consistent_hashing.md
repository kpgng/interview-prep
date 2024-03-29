# Consistent Hashing

Distributed Hash Table (DHT) is one of the fundamental components used in distributed scalable systems. Hash tables need a key, a value, and a hash function where hash functions maps the key to a location where the value is stored.

`index = hashFunction(key)`

Given 'n' cache servers, an intuitive hash function would be 'key % n'. It is simple and commonly used, but it has 2 major drawbacks:

1. It is NOT horizontally scalable. Whenever a new cache host is added to the system, all existing mappings are broken.
2. It may NOT be load balanced, especially for non-uniformly distributed data. For the caching system, it translates into some caches becoming hot and saturated while the others idle and are almost empty.

In such situations, consistent hashing is a good way to improve this.

___

## What is Consistent Hashing?

Consistent hashing allows us to distribute data across a cluster in such a way that will minimize reorganization when nodes are added or removed. When the hash table is resized (e.g., a new cache host is added to the system), only 'k / n' keys need to be remapped, where 'k' is the total number of keys, and 'n' is the total number of servers.

___

## How Does it Work?

As a typical hash function, consistent hashing maps a key to an integer. Suppose the output of the hash function is in the range of [0, 256). Imagine that the integers in the range are placed on a ring such that the values are wrapped around.

1. Given a list of cache servers, hash them to integers in the range.
2. To map a key to a server:
    - Hash it to a single integer.
    - Move CW on the ring until finding the first cache it encounters.
    - That cache is the one that contains the key.

![11_consistent_hashing](11_consistent_hashing.png)

To add a new server, say D, keys that were originally residing at C will be split. To remove a cache, or if a cache fails, say A, all keys that were originally mapped to A will fall into B, and only those keys need to be moved to B; other keys will not be affected.
