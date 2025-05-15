




# Python's frozenset class represents an immutable set.
# frozenset objects are like sets, but cannot be changed after creation.
#
# Usage:
#   frozenset([iterable]) -> creates a frozenset from any iterable (e.g., list, set, tuple)
#
# Example:
#   fs = frozenset([1, 2, 3])
#
# frozensets support set operations and can be used as dictionary keys or set elements.
#
# Common methods:
#   - copy(): returns a shallow copy of the frozenset
#   - difference(other): elements in self but not in other
#   - intersection(other): elements common to both sets
#   - isdisjoint(other): True if sets have no elements in common
#   - issubset(other): True if self is subset of other
#   - issuperset(other): True if self is superset of other
#   - symmetric_difference(other): elements in exactly one of the sets
#   - union(other): all elements from both sets
#
# frozenset is immutable, so methods that would modify a set (like add or remove) are not available.