# Caching

Caching enables us to make vastly better use of the resources we already have as well as making otherwise unattainable product requirements feasible. Caches take advantage of the locality of reference principle: recently requested data is likely to be requested again. A cache is like short-term memory: it has a limited amount of space, but is typically faster than the original data source and contains the most recently accessed items.

___

## Application Server Cache

Placing a cache directly on a request layer node enables the local storage of response data. Each time a request is made to the service, the node will quickly return local cached data if it exists. Expanding this to many nodes increases cache misses, 2 choices for overcoming this hurdle are global caches and distributed caches.

___

## Content Distribution Network (CDN)

CDNs are a kind of cache that comes into play for sites serving large amounts of static media. In a typical CDN setup, a request will first ask the CDN for a piece of static media; the CDN will serve that content if it has it locally available. If it isn't available, the CDN will query the backend servers for the file, cache it locally, and servce it to the requesting user.

___

## Cache Invalidation

If the data is modified in the database, it should be invalidated in the cache; if not, this can cause inconsistent application behavior. There are 3 main schemes that are used:

**Write-Through Cache:** Data is written into the cache and the corresponding database at the same time.

**Write-Around Cache:** Data is written directly to permanent storage, bypasssing the cache.

**Write-Back Cache:** Data is written to cache alone and completion is immediately confirmed to the client.

___

## Cache Eviction Policies

Most common cache eviction policies:

1. First In First Out (FIFO): Cache evicts the first block accessed first without any regard to how often or how many times it was accessed before.
2. Last In First Out (LIFO): The cache evicts the block accessed most recently first without any regard to how often or how many times it was accessed before.
3. Least Recently Used (LRU): Discards the least recently used items first.
4. Most Recently Used (MRU): Discards, in contrast to LRU, the most recently used items first.
5. Least Frequently Used (LFU): Counts how often an item is needed. Those that are used least often are discarded first.
6. Random Replacement (RR): Randomly selects a candidate item and discards it to make space when necessary.
