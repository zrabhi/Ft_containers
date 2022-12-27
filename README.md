#Stack unwinding
    *When a exception occurs while a fucntion is in progress on the stack, the call stack is returned while looking for the catch, and at this time, the stack is cleaned up each time the call stack is exited one by one, if the is memory allocated on the heap inside the stack, a leak occurs!(RAII is typical solution.)
    