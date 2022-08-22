# JSSync
## What can this be used for?
- Porting older code bases using sync xhr/io

## How to use

    /** ASYNC BEGIN */
    <insert async code here>
    /** ASYNC END */
Wrap ASYNC BEGIN AND END around asynchronous code blocks and with code splitting, will convert asynchronous program into synchronous. This also saves the stack while splitting.
