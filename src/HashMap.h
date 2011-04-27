
#ifndef HASHMAP_H_
#define HASHMAP_H_
#include <hash_map>
#include <unordered_map>

template<typename K, typename V>
class HashMap : Map<K, V, HashMap<K, V> > {



	template<typename Fn>
	void foreach0(Fn fn) {

	}
};



#endif /* HASHMAP_H_ */
