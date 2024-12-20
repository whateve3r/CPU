enum ErrorCodes
{
    STACK_OVERFLOW = 100,
    STACK_UNDERFLOW = 101,

    NULL_POINTER = 102,
    DATA_POINTER = 103,

    FIRST_CANARY_ERROR = 104,
    LAST_CANARY_ERROR = 105,

    NEGATIVE_SIZE = 106,
    NEGATIVE_CAPACITY = 107,

    SUCCESS = 108
};

enum Canary
{
    FIRST_CANARY = 0xAB0BA,
    LAST_CANARY = 0xDEDAB0BA
};

enum Commands
{
        OUT = 0,
        HLT = -1,

        PUSH = 1,
        POP = 2,

        MUL = 3,
        DIV = 4,
        SUM = 5,
        SUB = 6
};