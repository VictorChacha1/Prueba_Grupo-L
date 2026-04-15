# Prueba de Escritorio - Grupo L
## Sistema de Gestión - Taller Mecánico
### Universidad Técnica de Ambato

## Caso crítico analizado
Orden de tipo preventivo con mano de obra y un repuesto.

## Datos de entrada
| Dato | Valor |
|---|---|
| Tipo de servicio | preventivo |
| Horas de mano de obra | 3 |
| Costo por hora | $25.00 |
| Repuesto | Filtro de aceite x1 |
| Precio repuesto | $15.50 |

## Desarrollo paso a paso

Paso 1 - Costo de mano de obra:
3 horas x $25.00 = $75.00

Paso 2 - Costo de repuestos:
1 x $15.50 = $15.50

Paso 3 - Subtotal:
$75.00 + $15.50 = $90.50

Paso 4 - Descuento (preventivo = 10%):
$90.50 x 10% = $9.05
$90.50 - $9.05 = $81.45

Paso 5 - Impuesto (15%):
$81.45 x 15% = $12.22

Paso 6 - Valor final:
$81.45 + $12.22 = $93.67

Paso 7 - Clasificacion:
$93.67 es menor a $100 = Reparacion MENOR

## Resultado esperado
| Campo | Valor |
|---|---|
| Costo mano de obra | $75.00 |
| Costo repuestos | $15.50 |
| Descuento | $9.05 |
| Impuesto | $12.22 |
| Valor final | $93.67 |
| Clasificacion | Menor |

## Verificacion en el programa
El programa arrojo exactamente $93.67 y clasificacion Menor,
confirmando que la logica implementada es correcta.