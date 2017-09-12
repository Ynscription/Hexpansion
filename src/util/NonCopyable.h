#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H


struct NonCopyable {
	NonCopyable() = default;	//inheritors have a default costructor
	NonCopyable& operator = (const NonCopyable&) = delete; //inheritors can't use = operator (assignment) as it would copy
	NonCopyable(const NonCopyable&) = delete;	//doesn't allow inheritors to have copy constructor
};

#endif // NONCOPYABLE_H
