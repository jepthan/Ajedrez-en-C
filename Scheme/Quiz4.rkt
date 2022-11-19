#lang racket/base

(define (racional a b)
(cons a b))
(define (denominador r)
(cdr r))
(define (numerador r)
(car r))


(define (suma r1 r2)
(racional (+ (* (numerador r1) (denominador r2))
(* (denominador r1) (numerador r2)))
(* (denominador r1) (denominador r2))))

(define (resta r1 r2)
(racional (- (* (numerador r1) (denominador r2))
(*(denominador r1) (numerador r2)))
(* (denominador r1) (denominador r2))))

(define (producto r1 r2)
(racional (* (numerador r1) (numerador r2))
(* (denominador r1) (denominador r2))))

(define (division r1 r2)
(racional (* (numerador r1) (denominador r2))
(* (denominador r1) (numerador r2))))

(define (imprime r)
(newline)
(write (numerador r)) (write-char #\/ )
(write (denominador r)))

(define r1(racional 1 2))
r1

(define r2(racional 3 4))
r2

(imprime r1)
(imprime r2)

(define z (suma r1 r2))
z

(imprime z)

(define p (producto r1 z))
p

(imprime p)




(define a (list 5 4 6 7 8))

(define b (cons 5 (cons 4(cons 6(cons 7 (cons 8 '()))))))
a
b

(define w (append b (cons 8 '())))
w

(define L1 (list 'dos 'mas 'tres 'es 4))
L1
(define L2 (cons 'dos (cons 'mas (cons 'tres (cons 'es (cons 4 '()))))))
L2

(define (longitud L)
(if (null? L)
0
(+ 1 (longitud (cdr L)))))


(define (n-esimo n L)
(if (= n 1)
(car L)
(n-esimo (- n 1) (cdr L))))

(define (suma-lista L)
(if (null? L)
0
(+ (car L) (suma-lista (cdr L)))))


(define (pega L1 L2)
(if (null? L1)
L2
(cons (car L1) (pega (cdr L1) L2))))


(define (cuadrado-lista L)
(if (null? L)
'()
(cons (* (car L) (car L)) (cuadrado-lista (cdr L)))))


(define (multiplica-listas L1 L2)
(if (null? L1)
'()
(cons (* (car L1) (car L2)) (multiplica-listas (cdr L1) (cdr L2)))))

(define l1 '( 5 6 7))

(cons 5 l1)


