#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


#include <unordered_map>
#include <string>

template<typename Resource>
class ResourceManager {
	using CrString = const std::string&;

  public:
	ResourceManager (CrString folder, CrString extention)
		:   _folder    ("res/" + folder + "/")
		,   _extention ("." + extention) {
	}

	const Resource& get(CrString name) {
		if (!exists(name)) {
			add(name);
		}

		return _resources.at(name);
	}

	bool exists(CrString name) const {
		return _resources.find(name) != _resources.end();
	}

	void add(CrString name) {
		Resource r;

		//if the resource fails to load, then it adds a default "fail" resource
		if(!r.loadFromFile(getFullname(name))) {
			Resource fail;
			fail.loadFromFile(_folder + "_fail_" + _extention);
			_resources.insert(std::make_pair(name, fail));
		} else {
			_resources.insert(std::make_pair(name, r));
		}
	}

  private:
	std::string getFullname(CrString name) {
		return _folder + name + _extention;
	}

	const std::string _folder;
	const std::string _extention;

	std::unordered_map<std::string, Resource> _resources;	//Can't repeat names
};


#endif // RESOURCEMANAGER_H
