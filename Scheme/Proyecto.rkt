#lang racket
(require racket/trace)

(struct point (x y))

(define (igual p1 p2); revisa si los puntos p1 y p2 son iguales
  (if (and(=(point-x p1) (point-x p2)) (=(point-y p1) (point-y p2)))
      #t
      #f))

(define (ispointnull p1);revisa si el punto es null o  x = 0 y = 0
  (if (and(=(point-x p1) 0) (=(point-y p1) 0))
      #t
      #f
      )
  )



(define (check-conection p1 p2);Recibe dos strucs de point la primera es la
  ;posicion que prueba la segunda es la posicion actual
  (cond
     [(and (=(- (point-x p2) 1)(point-x p1)) (=(+ (point-y p2) 2) (point-y p1))) #t];Posicion 1 Done
     [(and (=(- (point-x p2) 2)(point-x p1)) (=(+ (point-y p2) 1) (point-y p1))) #t];Posicion 2 Done
     [(and (=(+ (point-x p2) 1)(point-x p1)) (=(+ (point-y p2) 2) (point-y p1))) #t];Posicion 3 Done
     [(and (=(+ (point-x p2) 2)(point-x p1)) (=(+ (point-y p2) 1) (point-y p1))) #t];Posicion 4 Done
     [(and (=(- (point-x p2) 2)(point-x p1)) (=(- (point-y p2) 1) (point-y p1))) #t];Posicion 5 Done
     [(and (=(- (point-x p2) 1)(point-x p1)) (=(- (point-y p2) 2) (point-y p1))) #t];Posicion 6 Done
     [(and (=(- (point-x p2) 2)(point-x p1)) (=(- (point-y p2) 1) (point-y p1))) #t];Posicion 7 Done
     [(and (=(- (point-x p2) 1)(point-x p1)) (=(- (point-y p2) 2) (point-y p1))) #t];Posicion 8 Done
     [else #f])
   )
  



(define (seRepite L p1) ; Revisa si p1 ya existe en la lista
  (if(null? L)
     #f
     (if (igual (car L) p1)
         #t
         (seRepite (cdr L) p1) 
         )
   ))


(define (isSafe p1 p2 L)
  (if (and (check-conection p1 p2) (not (seRepite (cdr L) p2)))
      #t
      #f
   ))

(define (check-valid p1)
  ((cond
     [(and (and(> (point-x p1) 0)(> (point-y p1) 0)) (and(<= (point-x p1) 8)(<= (point-y p1) 8))) (#t)]
     [else (#f)]
     )
   ));p1 checks if is incide board idkwhy

(define (longitud L)
  (if (null? L)
      0
      (+ 1 (longitud (cdr L)))
    )
  )



(define (aumentar p)
  (cond
    [(<(point-x p) 8) (point (+(point-x p)1) (point-y p))]
    [(and (=(point-x p) 8) (<(point-y p) 8)) (point 1 (+(point-y p)1))]
    [(=(point-y p)8)(point 0 0)]
    [else (point 0 0)]
    ))


(define (agregar L1 p)
  (cond
    [(isSafe (car L1) p L1) p]
    [(and(not(isSafe (car L1) p L1)) (ispointnull p)) p]
    [(not(isSafe (car L1) p L1)) (agregar L1 (aumentar p))]
    ))

(define (agregar1 L1 p)
  (cond
    [(isSafe (car L1) p L1) p]
    [(not(isSafe (car L1) p L1)) (agregar1 L1 (aumentar p))]
    ))

(define (principal L1 p)
  ;(printf "~S\n" (longitud L1))
  
  (if (=(longitud L1) 62)
      L1
      (cond
        [(ispointnull (car L1)) (principal (cddr L1) (aumentar(cadr L1)))]
        [else (principal (cons (agregar L1 p) L1) (point 1 1))]
    )
  )
)

(define l1 (cons(point 1 1) '()))
;(trace principal)

(principal l1 (point 1 1))


