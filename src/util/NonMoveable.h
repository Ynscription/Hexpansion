#ifndef NONMOVEABLE_H
#define NONMOVEABLE_H


struct NonMovable {
	NonMovable() = default;
	NonMovable& operator = (NonCopyable&&) = delete;
	NonMovable(NonCopyable&&) = delete;
};

#endif // NONMOVEABLE_H
