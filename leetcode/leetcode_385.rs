

pub enum NestedInteger {
    Int(i32),
    List(Vec<NestedInteger>)
}
struct Solution;
 pub fn get_value( s : String , start : usize, idx:usize) ->i32{
    let pos : usize = start as usize;
    let end : usize  = idx as usize;
    let t = s.get(pos..end).unwrap();
    let val =  t.parse::<i32>().unwrap();
    val
    }

    pub fn push_value(ni : &mut NestedInteger, val : i32) {
        match ni {
            NestedInteger::List(vec) => {
                vec.push(NestedInteger::Int(val))
            }
            _ => println!("", )
        }
    }
    pub fn add_val(ni : &mut NestedInteger, val : i32) {
         match ni {
            NestedInteger::List(vec ) => {
              let len = vec.len();
              let mut top = vec.as_slice()[len-1];
              vec.pop();
              if len > 1{
                let mut top_1 = vec.as_slice()[len-2];
                match top_1 {

                }
              }
            }
            _ => println!("", )
        }
    }
   
impl Solution {
   
    pub fn deserialize( s: String) -> NestedInteger {
        if s.len() == 0 {
            return NestedInteger::Int(0);
        }
        let bs = s.as_bytes();

        if bs[0] != '[' as u8{
            let value : i32 = s.parse::<i32>().unwrap();
            return NestedInteger::Int(value);
        }
        let ni = NestedInteger::List(Vec::new());
        let mut w : usize = 0;
        for x in 0..s.len() {
            if bs[x] == '[' as u8 {
                w = x + 1;
            } else if bs[x] == ',' as u8 {
                if x > w {
                push_value(&mut ni, get_value(s, w, x));
                w = x+1;
                }
            } else if bs[x] == ']' as u8 {
                if x > w {
                    add_val(&mut ni, get_value(s, w, x));
                    w = x + 1;
                }
            }
        }
        ni
    }

    

}

fn main() {

}