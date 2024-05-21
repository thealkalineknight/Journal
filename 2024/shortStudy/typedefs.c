// typedef is for defining something as a type. For instance:

typedef struct {
  int a;
  int b;
} THINGY;

// defines THINGY as the given struct. That way, you can use it like this:

THINGY t;

// rather than:

struct _THINGY_STRUCT {
  int a;
  int b;
};

struct _THINGY_STRUCT t;

// which is a bit more verbose. typedefs can make some things dramatically clearer, specially pointers to functions.
// Cpp does not require typedef because all "struct/union/enum/class declarations" are implicitly typedef
