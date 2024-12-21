function algorithm() {
    const arr = []

    for (let c = 0; c < 1000; c++) {
        arr.push(String(c).padStart(3, '0'))
    }

    for (let i = 0; i < arr.length; i++) {
        const [a, b, c] = arr[i].split('').map(Number)

        if (a === b || a === c || b === c) {
            arr.splice(i, 1)
            i--
        }
    }

    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            const [a, b, c] = arr[i].split('').map(Number)
            const [d, e, f] = arr[j].split('').map(Number)

            const permutations = new Set([
                `${a}${b}${c}`,
                `${a}${c}${b}`,
                `${b}${a}${c}`,
                `${b}${c}${a}`,
                `${c}${a}${b}`,
                `${c}${b}${a}`,

                `${d}${e}${f}`,
                `${d}${f}${e}`,
                `${e}${d}${f}`,
                `${e}${f}${d}`,
                `${f}${d}${e}`,
                `${f}${e}${d}`,
            ])

            if (permutations.size === 6) {
                arr.splice(j, 1)
                j--
            }
        }
    }

    return arr
}