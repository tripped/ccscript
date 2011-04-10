CCScript 2
==========

This is a quick (!) reimplementation of CCScript, intended to correct the more
offensive inadequacies of CCS 1.


What will change
----------------

There will be two major changes:

* CCScript 2 will be a Turing-complete programming language, instead of a
  glorified markup language with bytecode-generating macros.
* CCScript 2 will support language extensibility with syntax macros.

These changes will enable a shift from the CCS 1 model, in which a script was
primarily a "game script" annotated with control macros, which was compiled to
produce a chunk of EB text data. In CCS 2, a script will be a _program_ that is
run with the intent of producing such a chunk as an object file.

In short: in CCS 1, `ccc` was the compiler. In CCS 2, _the user's program_ is
the compiler.


The CCS 2 compiler model
------------------------

CCS 2 supports this "user program is compiler" model by breaking the program
into three main parts:

* One or more "assemblers," or schemas for producing object files in the target
  bytecode format,
* A set of syntax extensions that streamline the representation of target
  assemblies,
* And finally a program that uses those syntax extensions to represent, in a
  compact and readable way, a desired target assembly.

The power and expressiveness of CCS 2 comes from the fact that all of these
parts are written in the CCScript language and can interact with each other.

For the CCS 1 use case (scripts for EarthBound), the first two parts will be
provided already; however, the latter part will benefit enormously by having
greater programming power and reflective access to the assembler.


Examples
--------


### CCScript 1

EarthBound text scripts were the focus of CCS 1; they will be enabled as part
of the standard library provided with CCS 2.

In CCS1, scripts were built from macros (built-in keywords like `if` and `menu`
were effectively macros that evaluated to the corresponding EBCC bytecode); to
enable similar scripts in CCS 2, we would first write an assembler, which is
basically a set of functions or macros that produce bytecode output.

Then we would write syntax extensions that enables a CCS 1-style syntax:

    mylabel:
        "@Hey! Would you like to buy a dinosaur?" next
        menu {
            "Hell yes!" : goto(hellyes)
            default "Naw" : goto(nodinos)
        }

Labels are part of CCS 2's default syntax and don't need to be provided by our
extension; but we would have to provide the menu syntax and a few other things.
In this case, a menu syntax node would correspond to a menu production in our
assembler.

And that's it! CCS 1 scripts (or something very like them) are now usable in
CCS 2.


### SNES Assembler

One of the first "extensions" to CCScript was a set of macros that loosely
approximated 65816 assembly. This was great for writing ASM patches into the
ROM, but the syntax was kludgy:

    // Get current character number - 0x50
    LDX_d   (0x02)
    DEX
    LDA_x   (0x0000)
    AND_i   (0x00ff)
    SEC
    SBC_i   (0x50)
    TAX

With a CCS 2 extension, this could be written more naturally:

    ; Get current character number - 0x50
    LDX $02
    DEX
    LDA $0000,x
    AND #$00ff
    SEC
    SBC #$0050
    TAX



