// Basically just an over complicated xor logic function made in go

package xor

func xor4(a, b, c, d bool) bool {
	var sum, ck, as, bs, cs, ds bool 
	
	if a == true {if a == b || a == c || a == d {as = true} else {as = false}}
	if b == true {if b == a || b == c || b == d {bs = true} else {bs = false}}
	if c == true {if c == a || c == b || c == d {cs = true} else {cs = false}}
	if d == true {if d == a || d == b || d == c {ds = true} else {ds = false}}
	if !a && !b && !c && !d {ck = true}
	
	if !ck {if !as {if !bs {if !cs {if !ds {
		sum = true
	}}}}} else {
		sum = false
	}
	return sum
}
