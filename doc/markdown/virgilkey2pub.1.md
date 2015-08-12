NAME
====

**key2pub** -- get public key from the private key

SYNOPSIS
========

**virgil key2pub** [--in *file*] [--out *file*] [--pwd *arg*]

DESCRIPTION
===========

Get public key from the private key.

OPTIONS
=======

-i *file*, --in *file*  
Private key. If omitted stdin is used.

-o *file*, --out *file*  
Public key. If omitted stdout is used.

-p *arg*, --pwd *arg*  
Private key password.

SEE ALSO
========

`virgil(1)`, `virgilkeygen(1)`