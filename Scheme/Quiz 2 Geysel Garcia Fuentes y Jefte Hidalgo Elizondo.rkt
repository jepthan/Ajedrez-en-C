#lang racket/base

;Pregunta 1 parte 1
(define (Multiplica L)
  (if (null? L)
      1
      (* (car L) (Multiplica (cdr L)))))

;Test Pregunta 1 parte 1
(Multiplica '(1 2 3))

;Pregunta 1 parte 2
(define (Multiplical L1 L2)
  (if (null? L1)
      '()
      (cons (*(car L1) (car L2)) (Multiplical (cdr L1)(cdr L2))))
      )
;Test Pregunta 1 parte 2
(Multiplical '(1 2 3) '(2 2 2))


;Pregunta 1 parte 3
(define (aplica f L)
  (if (null? L)
      '()
      (cons (f (car L)) (aplica f (cdr L)))
      ))

;Pregunta 1 parte 4
(define (invierte L)
  (if (null? L)
      '()
      (append (invierte (cdr L)) (list (car L)))))

;pregunta 1 parte 5
;(define (ordena L))

;pregunta 1 parte 6
(define (sumalll L1 L2 L3)
  (if (null? L1)
      '()
      (cons (+ (+(car L1)(car L2))(car L3))(sumalll (cdr L1)(cdr L2)(cdr L3)))
      ))
;test pregunta 1 parte 7
(sumalll '(1 2 3) '(1 1 1) '(1 1 1))

(define (productolll L1 L2 L3)
  (if (null? L1)
      '()
      (cons (* (*(car L1)(car L2))(car L3))(productolll (cdr L1)(cdr L2)(cdr L3)))
      ))
;test pregunta 1 parte 7
(productolll '(1 2 3) '(1 1 1) '(1 1 1))

;pregunta 1 parte 8
;(define subconjunto L1 L2)

;pregunta 1 parte 9
(define (Eliminar X L)
  (if (null? L)
      '()
      (if (= X (car L))
          (cdr L)
          (cons (car L) (Eliminar X (cdr L)))
          )
      ))
(Eliminar 2 '(4 2 3 1 2))

;Pregunta 2 Divide L X (Divide '(7 1 4 3 2 4 2 4 6) 3) ---> ((1 3 2 2) (7 4 4 6))

(define (Divide L X)
  (if (null? L) '()
      (if (>= X (car L))
           (cons (car L) (Divide (cdr L)X))
           (cons (Divide (cdr L)X) (car L))
     )))
;test pregunta 2
(Divide '(7 1 4 3 2 4 2 4 6) 3)


;Ejercicio 3 parte 1
(define (Pertenece X L)
  (if (null? L)
      #f
      (if (= X (car L))
          #t
          (Pertenece X (cdr L))
          )
      ))
(Pertenece 8 '(4 2 3 1 2))

;Ejercicio 3 parte 2

(define (Resta L1 L2)
  (if(null? L1)
     '()
     (if(Pertenece (car L1) L2)
        (Resta (cdr L1) L2)
        (cons (car L1) (Resta (cdr L1) L2))
        )
     ))

(Resta '(7 1 4 3 2 4 2 4 6) '(5 1 4))


;Pregunta 4
(define (Pares L1 L2)
  (if (null? L1)
      '()
      (cons (cons (car L1)(cons (car L2) '())) (Pares (cdr L1) (cdr L2)))))
;Pregunta 4 test
(Pares '(7 1 4 3 4) '(5 1 4 -1 1))